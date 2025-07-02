const assert = require('assert');
const path = require('path');
const { metacall_execution_path, metacall_load_from_package_export } = require('metacall');

// Load a C file and execute it
const { sum_doubles, mult_longs } = require('./c/math.c');

assert(sum_doubles(3.0, 4.0), 7.0);
assert(mult_longs(2, 4), 8);

// Define where the C++ headers are located (inside the cpp folder we will find test.h)
metacall_execution_path('c', path.join(__dirname, 'cpp'));

// Load a C++ library and execute it (this will load test.h and libtest.so)
const { fibonacci } = metacall_load_from_package_export('c', path.join(__dirname, 'cpp', 'test'));

// Call to the C++ function
assert(fibonacci(8), 21);
