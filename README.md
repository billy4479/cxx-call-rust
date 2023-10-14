# Rust Qt6 Template

This repo includes 3 components:

- `crates/my-crate`, Rust: implement all the business logic here
- `crates/cxx-bindings`, Rust: write all the glue code you might need
- `src`, C++: the Qt app that will implement the GUI

This project is build with `cmake` that will call `cargo` to build the rust crates.
A `build.sh` is provided for convenience.

## License

This template is [public domain](https://creativecommons.org/public-domain/cc0/). Have fun!
