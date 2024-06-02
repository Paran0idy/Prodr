#include <mlir/IR/Builders.h>
#include <mlir/IR/MLIRContext.h>

#include "Prodr/Dialect/Prodr/IR/Dialect.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/ValueRange.h"
#include "llvm/Support/raw_ostream.h"


using namespace mlir;
using namespace prodr;

int main(int argc, char **argv) {
    mlir::MLIRContext context;
    context.loadDialect<arith::ArithDialect,
                        func::FuncDialect,
                        prodr::ProdrDialect
                        >();


    mlir::OpBuilder builder(&context);
    auto moduleOp = builder.create<ModuleOp>(builder.getUnknownLoc());

    builder.setInsertionPointToEnd(moduleOp.getBody());


    auto i32 = builder.getI32Type();
    auto funcType = builder.getFunctionType({i32, i32}, {i32});
    auto func = builder.create<func::FuncOp>(builder.getUnknownLoc(), "main", funcType); 

    auto entry = func.addEntryBlock();
    auto args = entry->getArguments();

    builder.setInsertionPointToEnd(entry);
    auto addi = builder.create<arith::AddIOp>(builder.getUnknownLoc(), args);
    builder.create<func::ReturnOp>(builder.getUnknownLoc(), ValueRange(addi));

    moduleOp->print(llvm::outs());
    return 0;
}