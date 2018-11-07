<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Entities\EntryLog;
use App\Entities\Pagination;
use Illuminate\Support\Facades\App;

class LogController extends Controller
{
    private $_entries = [];
    private $_allEntries = [];
    private $_currPage = 1;
    private $_elemPerPage = 1;
    private $_pathLog;

    public function __construct()
    {
        $this->_pathLog = base_path() . "/../kift.log";
        $this->_parseEntries();

    }

    public function index(Request $request) {

        $page = $request->get('page');
        $query = strtolower(trim($request->get('query')));
        $query = preg_replace("/\[|\]/", '', $query);

        if (!empty($page) && is_numeric($page) && $page > 1) {
            $this->_currPage = $page;
        }

//        dd($query);

        $this->_filterEntries($query);
        $data = [
            'level' => 'all',
            'query' => $request->get('query'),
            'entries' => $this->_entries,
            'pagination' => new Pagination(),//class

        ];

        return view('logs', $data);
    }

    private function _parseEntries() {
        if ($file = fopen($this->_pathLog, "r")) {
            while(!feof($file)) {
                $line = fgets($file);
                if (!empty($line)) {
                    array_unshift($this->_allEntries, new EntryLog($line));
                }
            }
            fclose($file);
        }
    }

    private function _filterEntries(string $query) {

        $query = preg_quote($query);

        foreach ($this->_allEntries as $key => $entry) {
            if (preg_match("/" . $query . "/", $entry->raw)) {
                $this->_entries[] = $entry;
            }
        }

    }

}
