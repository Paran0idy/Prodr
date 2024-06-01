add_mlir_dialect_library(MLIRProdr
    ProdrOps.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include/

    DEPENDS ProdrTableGen


    LINK_LIBS PUBLIC
    MLIRIR
    MLIRArithDialect
    MLIRMathDialect
    MLIRSCFDialect
)