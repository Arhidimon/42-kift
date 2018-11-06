<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Entities\EntryLog;
use App\Entities\Pagination;
use Illuminate\Support\Facades\App;

class LogController extends Controller
{
    private $entries;

    public function __construct()
    {
        $this->entries = [new EntryLog("12-12- df sdf"), new EntryLog("1231 132  121")];
    }

    public function index(Request $request) {
        $data = [
            'level' => 'all',
            'query' => $request->get('query'),
            'entries' => $this->entries,
            'pagination' => new Pagination(),//class

        ];

        return view('logs', $data);
    }
}
