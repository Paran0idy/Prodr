set(MLIR_BINARY_DIR ${CMAKE_BINARY_DIR})


set(LLVM_TARGET_DEFINITIONS ProdrOps.td)
mlir_tablegen(Ops.h.inc -gen-op-decls)
mlir_tablegen(Ops.cpp.inc -gen-op-defs)
add_mlir_doc(ProdrOps ProdrOps dialects/ -gen-op-doc)


set(LLVM_TARGET_DEFINITIONS ProdrDialect.td)
mlir_tablegen(Dialect.h.inc -gen-dialect-decls)
mlir_tablegen(Dialect.cpp.inc -gen-dialect-defs)
add_mlir_doc(ProdrDialect ProdrDialect dialects/ -gen-dialect-doc)


add_public_tablegen_target(ProdrTableGen)