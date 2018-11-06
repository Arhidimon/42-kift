<?php
/**
 * Created by PhpStorm.
 * User: shkykavyi
 * Date: 06.11.18
 * Time: 19:26
 */

namespace App\Entities;

use Carbon\Carbon;


class EntryLog
{
    /** @var string */
    public $status;

    /** @var \Carbon\Carbon */
    public $datetime;

    /** @var string */
    public $command;

    public $header;

    public $text;

    //more info

    public function __construct($raw)
    {
        //parse
        preg_match_all("/\[(.*?)\]/", $raw, $matches);
//        dd($matches);
        if (!empty($matches)) {
            $this->status = $matches[1][2];
            $this->datetime = Carbon::parse($matches[1][0]);
            $this->command = $matches[1][1];
            $this->text = $matches[1][3];
        }
        $this->header = (!empty($this->command)) ? $this->command : $this->text;
    }
}
