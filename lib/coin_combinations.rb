require 'ffi'

module CoinCombinationsExtention
  extend FFI::Library
  ffi_lib FFI::Library::LIBC
  ffi_lib 'c'
  ffi_lib 'coin_combinations.so'
  attach_function :GetUserChange, [:int, :pointer], :string
end

module LibC
  extend FFI::Library
  ffi_lib FFI::Library::LIBC
  attach_function :malloc, [:size_t], :pointer
  attach_function :free, [:pointer], :void
end

class CoinCombination
  define_singleton_method(:get_change) do |from_dollars|
    rsltPtr = LibC::malloc 256
    CoinCombinationsExtention::GetUserChange(from_dollars, rsltPtr)
    rsltString = rsltPtr.read_string;
    LibC::free rsltPtr
    return rsltString
  end
end
