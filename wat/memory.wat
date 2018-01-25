(module
  (memory (import "js" "mem") 1)
  (func (export "add") (param $one i32) (param $two i32) (result i32)
    (i32.load (get_local $one))
    (i32.load (i32.mul (get_local $two)
                       (i32.const 4)))
    (i32.add)))