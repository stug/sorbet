#ifndef SORBET_COMPILER_LLVMIREMITTER_INTRINSICS_H
#define SORBET_COMPILER_LLVMIREMITTER_INTRINSICS_H

#include "IREmitterHelpers.h"
#include <string_view>
#include <vector>

namespace sorbet::compiler {

struct BasicBlockMap;

class NameBasedIntrinsicMethod {
public:
    const bool blockHandled;
    virtual llvm::Value *makeCall(CompilerState &cs, cfg::Send *i, llvm::IRBuilderBase &builder,
                                  const BasicBlockMap &blockMap,
                                  const UnorderedMap<core::LocalVariable, Alias> &aliases, int rubyBlockId,
                                  llvm::Function *blk) const = 0;
    virtual InlinedVector<core::NameRef, 2> applicableMethods(CompilerState &cs) const = 0;
    NameBasedIntrinsicMethod(bool blockHandled) : blockHandled(blockHandled){};
    virtual ~NameBasedIntrinsicMethod() = default;
    static const std::vector<const NameBasedIntrinsicMethod *> &definedIntrinsics();
};
}; // namespace sorbet::compiler
#endif
