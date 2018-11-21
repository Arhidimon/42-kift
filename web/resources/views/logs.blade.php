@extends('_master')

@section('content')

    <div class="row justify-content-center">

        <div class="col-12 col-lg-10">
            {{-- Log Details --}}
            <div class=" mb-4">

                {{-- Search --}}
                <form action="/" method="GET">
                    <div class=form-group">
                        <div class="input-group">
                            <input id="query" name="query" class="form-control" value="{{ $query }}"
                                   placeholder="Type here to search">
                            <div class="input-group-append">
                                {{--@unless (is_null($query))--}}
                                {{--<a href="{{ route('log-viewer::logs.show', [$log->date]) }}" class="btn btn-secondary">--}}
                                {{--({{ $entries->count() }} results) <i class="fa fa-fw fa-times"></i>--}}
                                {{--</a>--}}
                                {{--@endunless--}}
                                <button id="search-btn" class="btn btn-primary">
                                    <span class="fa fa-fw fa-search"></span>
                                </button>
                            </div>
                        </div>
                    </div>
                </form>
            </div>

            {{-- Log Entries --}}
            <div class="card mb-4">
                @if ($pagination->hasPages())
                    <div class="card-header">
                        <span class="badge badge-info float-right">
                            Page {{ $pagination->currentPage() }} of {{ $pagination->lastPage() }}
                        </span>
                    </div>
                @endif

                <div class="table-responsive">
                    <table id="entries" class="table mb-0">
                        <thead>
                        <tr>
                            <th>status</th>
                            <th style="width: 120px;">Date</th>
                            <th style="width: 65px;">Time</th>
                            <th>Header</th>
                            <th class="text-right">Actions</th>
                        </tr>
                        </thead>
                        <tbody>
                        @forelse($entries as $key => $entry)
                            <tr>
                                <td>
                                    @if($entry->status == "success")
                                        <span class="badge badge-success ">{{ $entry->status }}</span>
                                    @else
                                        <span class="badge badge-danger ">{{ $entry->status }}</span>
                                    @endif
                                </td>
                                <td>
                                        <span class="badge badge-secondary">
                                            {{ $entry->datetime->format('Y-m-d') }}
                                        </span>
                                </td>
                                <td>
                                        <span class="badge badge-secondary">
                                            {{ $entry->datetime->format('H:i:s') }}
                                        </span>
                                </td>
                                <td>
                                    {{ $entry->header }}
                                </td>
                                <td class="text-right">
                                    {{--                                        @if ($entry->hasStack())--}}
                                    <a class="btn btn-sm btn-light" role="button" data-toggle="collapse"
                                       href="#log-stack-{{ $key }}" aria-expanded="false"
                                       aria-controls="log-stack-{{ $key }}">
                                        <i class="fa fa-toggle-on"></i> Details
                                    </a>
                                    {{--@endif--}}
                                </td>
                            </tr>
                            <tr>
                                <td colspan="5" class="stack py-0">
                                    <div class="stack-content collapse mt-0" id="log-stack-{{ $key }}">
                                        {{ $entry->text }}<br>
                                    </div>
                                </td>
                            </tr>
                        @empty
                            <tr>
                                <td colspan="5" class="text-center">
                                    <span class="badge badge-secondary">Empty logs</span>
                                </td>
                            </tr>
                        @endforelse
                        </tbody>
                    </table>
                </div>
            </div>

        </div>
    </div>
@endsection

