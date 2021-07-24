# frozen_string_literal: true
# typed: strict
# compiled: true

class AttrReaderSigUncheckedForceIVAR
  extend T::Sig
  sig {params(foo: Integer).void}
  def initialize(foo)
    @foo = foo
  end

  sig {returns(Integer).checked(:never)}
  attr_reader :foo

  # This is here to trick the compiler into redefining the method using
  # `attr_reader`, which the VM special cases.
  self.send(:attr_reader, :foo)
end

x = AttrReaderSigUncheckedForceIVAR.new(1248)

i = 0
while i < 10_000_000

  x.foo

  i += 1
end

puts i
puts x.foo
