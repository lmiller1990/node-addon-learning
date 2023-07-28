## Node Addon API

I am learning about C++ via studying Node.js, v8 and learning to write some addons. 

I found out there are many ways to talk to v8 / Node.js via C++:

1. v8 APIs
2. nan
3. Node API
4. Node Addon API

Each one builds on the previous layer.

I learned some basic things like sending data back and forth between JavaScript running in Node.js and C++. I'm trying to find out how to the equivalent in C++ of the following JS:

```js
const { Greet } = require("./greeter");
const greet = new Greet(name);
greet.greet();
```

I understanding "writing JS in C++" isn't really the point of the Addon API, but I'm still interested in how I might accomplish something like this. Is Node Addon API / Node API the right abstraction? Or do I need to use nan (much lower level than I'm currently comfortable with, but I'm learning fast!)

## Running

```
npm install
node-gyp build
node src/binding.js
```
