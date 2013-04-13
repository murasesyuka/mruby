##
# Numeric ISO Test

assert('Numeric', '15.2.7') do
  Numeric.class == Class
end

assert('Numeric superclass', '15.2.7.2') do
  Numeric.superclass == Object
end

assert('Numeric#+@', '15.2.7.4.1') do
  +1 == +1
end

assert('Numeric#-@', '15.2.7.4.2') do
  -1 == -1
end

assert('Numeric#abs', '15.2.7.4.3') do
  1.abs == 1 and -1.abs == 1.0
end

# Not ISO specified

assert('Numeric#**') do
  2.0**3 == 8.0
end

assert('Integer#udiv') do
  4.udiv 3 == 1
end

assert('Integer#udiv_round') do
  192.udiv_round(127) == 2
  192.udiv_round(128) == 2
  192.udiv_round(129) == 1
end
