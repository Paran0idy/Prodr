include "mlir/IR/OpBase.td"

def Prodr_Dialect : Dialect {
    let name = "Prodr";
    let cppNamespace = "::mlir::prodr";
    let summary = "Prodr Dialect";

    let description = [{
        Prodr Dialect
    }];

    let dependentDialects = [
        "arith::ArithDialect"
    ];
}