assert('Integer#udiv') do
  4.udiv 3 == 1
end

assert('Integer#udiv_round') do
  192.udiv_round(127) == 2
  192.udiv_round(128) == 2
  192.udiv_round(129) == 1
end
