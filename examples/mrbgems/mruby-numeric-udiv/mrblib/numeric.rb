class Integer
  def udiv_round(num)
    a, b = self, num.to_i
    (a + b.udiv(2)).udiv(b)
  end
end
