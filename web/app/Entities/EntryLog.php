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
    public $level;

    /** @var \Carbon\Carbon */
    public $datetime;

    /** @var string */
    public $header;

    //more info

    public function __construct($raw)
    {
        //parse
        $this->level = "info";
        $this->datetime = Carbon::now();
        $this->header = "some header";
    }
}
