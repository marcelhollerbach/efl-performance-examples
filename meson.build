project('efl-performance-test', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

elm = dependency('elementary')

executable('no-scroller',
           'no_scroller.c',
	   dependencies : elm,
           install : true)

executable('scroller',
           'scroller.c',
	   dependencies : elm,
           install : true)
