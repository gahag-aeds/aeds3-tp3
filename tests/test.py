#!/usr/bin/env python3

import os, sys, itertools

import tptester


tests_dir = os.path.dirname(os.path.realpath(__file__))


tptester.tp_test(
  itertools.product(
    [ 500, 700, 1000, 1200, 1500, 1800, 2000 ],
    [ 5, 10, 20, 25, 50 ]
  ),
  
  os.getcwd() + '/' + sys.argv[1],
  
  #valgrind = True,
  
  #graph = True,
  
  input_file = lambda ix:  tests_dir + '/data/tests/' + str(ix[0]) + '_' + str(ix[1]) + '.in',
  answer_file = lambda ix: tests_dir + '/data/tests/' + str(ix[0]) + '_' + str(ix[1]) + '.out',
  
  args = lambda ix: [ ],
  stdin = lambda ifile: ifile,
  output = lambda ofile, stdout: stdout
)
