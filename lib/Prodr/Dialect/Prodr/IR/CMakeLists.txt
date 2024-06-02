add_mlir_dialect_library(MLIRProdr
    Ops.cpp

    DEPENDS ProdrTableGen

    LINK_LIBS PUBLIC
    MLIRIR
)