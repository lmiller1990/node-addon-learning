const mod = require("../build/Release/addon-native.node");

// Is there some way to this using node-addon-api?
// I couldn't find any examples of
// 1. using `require` in node-addon-api
// 2. creating a new instance of a constructor
// 3. calling a method on an instance
const { Greet } = require("./greeter");
const greet = new Greet("alice");
greet.greet();

global.Greet = Greet;

global.doJs = function (name) {
  const { Greet } = require("./greeter");
  const greet = new Greet(name);
  greet.greet();
};

mod.method("Alice");
