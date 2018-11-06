<?php
/**
 * Created by PhpStorm.
 * User: shkykavyi
 * Date: 06.11.18
 * Time: 20:02
 */

namespace App\Entities;


class Pagination
{
    private $pages;
    private $currentPage;
    private $perPage = 5;

    public function currentPage() {
        return 1;
    }

    public function lastPage() {
        return $this->pages;
    }

    public function hasPages() {
        return ($this->pages > 1);
    }

}
