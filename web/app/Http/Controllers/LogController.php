<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class LogController extends Controller
{
    public function index() {
        $data = [
            'logs' => [
                [
                    'title' => 'titile 1',
                    'date' => '13-12-2018 12:12:12',
                ],
                [
                    'title' => 'titile 2',
                    'date' => '13-12-2018 12:12:12',
                ],
                [
                    'title' => 'titile 3 1231 23 123 123 42gfk jdfg hkfsdg ',
                    'date' => '13-12-2018 12:12:12',
                ]

            ]
        ];

        return view('logs', $data);
    }
}
