use my_crate::add;

#[cxx::bridge]
mod ffi {
    extern "Rust" {
        pub fn add(left: usize, right: usize) -> Result<usize>;
    }
}
