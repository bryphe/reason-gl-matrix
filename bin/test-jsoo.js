// The stubs require glMatrix to be present, so we'll
// bring it in the global namespace here.
const glMatrix = require("./../js/gl-matrix-min.js");

// Bring all the items, like `mat4` and `vec` into the global namespace
Object.keys(glMatrix).forEach((key) => {
    global[key] = glMatrix[key];
});

// Run our tests
const test = require("./../_build/default/test/bin/test_runner.bc.js");
