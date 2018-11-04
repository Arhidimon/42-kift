#!/bin/sh

composer install;
php artisan storage:link;
cp .env.example .env
php artisan key:generate;

