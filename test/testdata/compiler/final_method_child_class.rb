# typed: true
# compiled: true
# frozen_string_literal: true

class Parent
  extend T::Sig
  extend T::Helpers

  sig(:final) {void}
  def final_method
    puts "final method!"
  end
end

class Child < Parent; end

# This method call exposes a limitation of the current implementation: we don't
# use `findMemberTransitive` to find the final method in Parent, and so this
# won't end up being a direct call in the generated llvm.
Child.new.final_method
