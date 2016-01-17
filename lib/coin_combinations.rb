require 'ffi'

module CoinCombinationsExtention
  extend FFI::Library
  ffi_lib 'c'
  ffi_lib 'coin_combinations.so'
  attach_function :GetUserChange, [:int], :string
end

class CoinCombination
  define_singleton_method(:get_change) do |from_dollars|
    CoinCombinationsExtention::GetUserChange(from_dollars)
  end
end
