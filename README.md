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
const path = require('path')
const { Greet } = require("./greeter");
const greet = new Greet(name);
greet.greet();
```

I looked at [some examples](https://github.com/nodejs/node-addon-examples/tree/3eaf06f5f285fe7b6892108e8ec5e5eed9da7791) which were pretty useful, but there is a few things I couldn't figure out the correct syntax for in C++ using Node Addon API, namely:

1. can I `require` or get a handle on a JS module from userland? 
2. how about accessing Node.js APIs in C++? Can I access `path`, `vm`, `fs` etc?
3. creating a new instance of a class / function? Is this something I can do in C++?
4. calling a method on an object? eg `const path = require('path'); path.join(...)`? Can I do this using a C++ API?

I understanding "writing JS in C++" isn't really the point of the Addon API, but I'm still interested in how I might accomplish something like this. Is Node Addon API / Node API the right abstraction? Or do I need to use nan (much lower level than I'm currently comfortable with, but I'm learning fast!)

Someone shared with me  one example doing something sort of similar. [This user](https://zhuanlan.zhihu.com/p/376638202?utm_id=0) (Chinese article, I used Google Translate to read it) is doing something like this using C++ (via Rust). He uses the `vm` module to create a new `Script` instance and calls a method on it - so it seems this is possible in some fashion? That user is doing it for security purposes, which is a pretty neat use case.

He says he does the following equivalent in Rust - he also says "the original Rust code is too long to post" - maybe this is more complex than I'm expecting.

```js
const vm = require('vm');

const script = vm.Script(dummyCode, {
  cachedData, // 这个就是字节码
  filename,
  lineOffset: 0,
  displayErrors: true
});

script.runInThisContext({
  filename,
  lineOffset: 0,
  columnOffset: 0,
  displayErrors: true
});
```

## Running

```
npm install
node-gyp build
node src/binding.js
```
