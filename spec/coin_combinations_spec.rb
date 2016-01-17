require 'coin_combinations'

describe CoinCombination do
  it "takes the input of 1 and changes it to '1 penny'" do
    expect(CoinCombination.get_change(1)).to(eq("1 penny"))
  end
  it "takes the input of 3 and changes it to '3 pennies'" do
    expect(CoinCombination.get_change(3)).to(eq("3 pennies"))
  end
  it "takes the input of 8 and changes it to '1 nickel and 3 pennies'" do
    expect(CoinCombination.get_change(8)).to(eq("1 nickel 3 pennies"))
  end
  it "takes the input of 13 and changes it to '1 dime and 3 pennies'" do
    expect(CoinCombination.get_change(13)).to(eq("1 dime 3 pennies"))
  end
  it "takes the input of 43 and changes it to '1 quarter 1 dime 1 nickel 3 pennies'" do
    expect(CoinCombination.get_change(43)).to(eq("1 quarter 1 dime 1 nickel 3 pennies"))
  end
end
