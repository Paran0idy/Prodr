include "Prodr/Dialect/Prodr/IR/ProdrDialect.td"
include "mlir/IR/OpBase.td"
include "mlir/IR/SymbolInterfaces.td" // SymbolUserOpInterface
include "mlir/IR/OpAsmInterface.td" // OpAsmOpInterface
include "mlir/Interfaces/CallInterfaces.td" // CallOpInterface
include "mlir/Interfaces/CastInterfaces.td" // CastOpInterface
include "mlir/Interfaces/FunctionInterfaces.td" // FunctionOpInterface
include "mlir/Interfaces/SideEffectInterfaces.td" // Pure
include "mlir/Interfaces/ControlFlowInterfaces.td" // BranchOpInterface
include "mlir/Interfaces/InferTypeOpInterface.td" // SameOperandsAndResultType
include "mlir/Interfaces/SideEffectInterfaces.td" // Pure
include "mlir/Interfaces/CastInterfaces.td" // CastOpInterface
include "mlir/Interfaces/CallInterfaces.td" // CallOpInterface



class Prodr_Op<string mnemonic, list<Trait> traits = []> : Op<Prodr_Dialect, mnemonic, traits> {

}


def Prodr_ConstantOp : Prodr_Op<"constant", [Pure]> {
    let summary = "Constant";

    let description = [{
        ```mlir
        prodr.constant = dense<[1.0, 2.0]> : tensor<2xf32>
        ```
    }];


    let arguments = (ins F64ElementsAttr: $value);
    let results = (outs F64Tensor);
}