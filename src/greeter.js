class Greet {
  #name;

  constructor(name) {
    console.log("Creating with name: ", name);
    this.#name = name;
  }

  greet() {
    console.log(`Hello, ${this.#name}!`);
  }
}

module.exports = {
  Greet,
};
