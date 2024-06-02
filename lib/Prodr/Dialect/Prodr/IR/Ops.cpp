#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinAttributes.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/OperationSupport.h"
#include "mlir/Support/LLVM.h"
#include "Prodr/Dialect/Prodr/IR/Ops.h"
#include <mlir/IR/MLIRContext.h>


#define GET_OP_CLASSES
#include "Prodr/Dialect/Prodr/IR/Ops.cpp.inc"

using namespace mlir::prodr;
void ProdrDialect::initialize() {
    addOperations<
#define GET_OP_LIST 
#include "Prodr/Dialect/Prodr/IR/Ops.cpp.inc"
    >();
}

using namespace mlir;