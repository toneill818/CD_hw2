add_library (lib ast.cpp parser.cpp evaluate.cpp postfix.cpp sexpr.cpp type_ast.cpp symbol.cpp token.cpp Lexer.cpp typeCheck.h)
target_include_directories (lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})