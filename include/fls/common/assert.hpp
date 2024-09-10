#ifndef FLS_COMMON_ASSERT_HPP
#define FLS_COMMON_ASSERT_HPP

#ifdef NDEBUG
#define FLS_ASSERT(...)          ;
#define DETAILED_FLS_ASSERT(...) ;

#else
#define FLS_ASSERT(Expr, Val, Msg)          fastlanes::FlsAssert(#Expr, Val, Expr, __FILE__, __LINE__, Msg)
#define DETAILED_FLS_ASSERT(Expr, Val, Msg) fastlanes::DetailedFlsAssert(#Expr, Val, Expr, __FILE__, __LINE__, Msg)
#endif

#define FLS_ASSERT_EXPR(Expr)                   DETAILED_FLS_ASSERT(Expr, " ", #Expr);
#define FLS_ASSERT_TRUE(Expr)                   FLS_ASSERT(Expr, " ", #Expr);
#define FLS_ASSERT_FALSE(EXPR)                  FLS_ASSERT(!(EXPR), " ", #EXPR);
#define FLS_ASSERT_NOT_NULL_POINTER(Expr)       FLS_ASSERT(Expr != nullptr, " ", fastlanes::assert::NULL_POINTER);
#define FLS_ASSERT_NULL_POINTER(Expr)           FLS_ASSERT(Expr == nullptr, " ", "");
#define FLS_ASSERT_CORRECT_MIN_MAX(Min, Max)    FLS_ASSERT(Max >= Min, " ", fastlanes::assert::NULL_POINTER);
#define FLS_ASSERT_CORRECT_RANGE(Range)         FLS_ASSERT(Range >= 0, " ", fastlanes::assert::CORRECT_BW);
#define FLS_ASSERT_CORRECT_BW(Bw)               DETAILED_FLS_ASSERT(Bw >= 0 && Bw <= 64, #Bw, fastlanes::assert::NULL_POINTER);
#define FLS_ASSERT_NOT_ZERO(Expr)               FLS_ASSERT(Expr != 0, " ", fastlanes::assert::ZERO);
#define FLS_ASSERT_ZERO(Expr)                   FLS_ASSERT(Expr == 0, " ", fastlanes::assert::NOT_ZERO);
#define FLS_ASSERT_CORRECT_SZ(Expr)             FLS_ASSERT(Expr >= 0, " ", fastlanes::assert::NEGATIVE_SZ);
#define FLS_ASSERT_CORRECT_BSZ(Expr)            FLS_ASSERT(Expr >= 0, " ", fastlanes::assert::NEGATIVE_SZ);
#define FLS_ASSERT_CORRECT_EXP_T(EXP_T)         FLS_ASSERT(EXP_T != 0, #EXP_T, fastlanes::assert::CORRECT_EXP_T_MSG);
#define FLS_ASSERT_CORRECT_N(Expr)              FLS_ASSERT(Expr >= 0, " ", fastlanes::assert::NEGATIVE_INDEX);
#define FLS_ASSERT_CORRECT_LMTED_C(C, LMT)      FLS_ASSERT(C >= 0 && C = < LMT, " ", fastlanes::assert::NEGATIVE_INDEX);
#define FLS_ASSERT_CORRECT_POS(POS)             FLS_ASSERT(POS >= 0 && POS <= 1023, " ", fastlanes::assert::NEGATIVE_INDEX);
#define FLS_ASSERT_CORRECT_SEGMENT_SIZE(Expr)   FLS_ASSERT(Expr >= 8, " ", "");
#define FLS_ASSERT_EQUALITY(L_Expr, R_Expr)     FLS_ASSERT(L_Expr == R_Expr, " ", " ");
#define FLS_ASSERT_LESS(L_Expr, R_Expr)         FLS_ASSERT(L_Expr <= R_Expr, " ", " ");
#define FLS_ASSERT_G(L_VAL, R_VAL)              FLS_ASSERT(L_VAL > R_VAL, " ", " ");
#define FLS_ASSERT_GE(L_VAL, R_VAL)             FLS_ASSERT(L_VAL >= R_VAL, " ", " ");
#define FLS_ASSERT_L(L_VAL, R_VAL)              FLS_ASSERT(L_VAL < R_VAL, " ", " ");
#define FLS_ASSERT_LE(L_VAL, R_VAL)             FLS_ASSERT(L_VAL <= R_VAL, " ", " ");
#define FLS_ASSERT_CORRECT_NUM(NUM, C)          FLS_ASSERT(NUM <= C, " ", " ");
#define FLS_ABORT(MSG)                          FLS_ASSERT(false, MSG, fastlanes::assert::ABORT);
#define FLS_ASSERT_CORRECT_BASE_UB(BASE, UB)    FLS_ASSERT(BASE <= UB, " ", fastlanes::assert::BASE_UB);
#define FLS_ASSERT_CORRECT_BASE_LB(BASE, LB)    FLS_ASSERT(BASE >= LB, " ", fastlanes::assert::BASE_LB);
#define FLS_ASSERT_CORRECT_OFFSET(Offset)       FLS_ASSERT(Offset >= 0, " ", fastlanes::assert::OFFSET);
#define FLS_ASSERT_CORRECT_SMART_OFFSET(OFFSET) FLS_ASSERT(OFFSET >= 0, " ", fastlanes::assert::SMART_OFFSET);
#define FLS_ASSERT_CORRECT_EXC_C(C)             FLS_ASSERT(C <= 1024 && C >= 0, " ", fastlanes::assert::ZERO);
#define FLS_ASSERT_NOT_EMPTY_STR(STR)           FLS_ASSERT(STR.size() > 0, " ", " ");
#define FLS_ASSERT_E(L_VAL, R_VAL)              FLS_ASSERT(L_VAL == R_VAL, " ", " ");
#define FLS_ASSERT_CORRECT_IDX(Expr)            FLS_ASSERT(Expr >= 0, " ", fastlanes::assert::IDX);
#define FLS_ASSERT_NOT_EMPTY_VEC(VEC)           FLS_ASSERT(!VEC.empty(), " ", fastlanes::assert::EMPTY_VECTOR);

namespace fastlanes {
void FlsAssert(const char* expr_str, const char* str, bool expr, const char* file, int line, const char* msg);
void DetailedFlsAssert(const char* expr_str, const char* str, bool expr, const char* file, int line, const char* msg);

class assert {
public:
	static constexpr auto CORRECT_EXP_T_MSG      = "Exp is invalid.";
	static constexpr auto ABORT                  = "ABORTED.";
	static constexpr auto NEGATIVE_INDEX         = "Negative index.";
	static constexpr auto NEGATIVE_SZ            = "Negative sz.";
	static constexpr auto EMPTY_CONTAINER_ACCESS = "Empty container access.";
	static constexpr auto OUT_OF_RANGE_INDEX     = "Out of range index.";
	static constexpr auto NULL_POINTER           = "Null Pointer.";
	static constexpr auto ZERO                   = "= 0.";
	static constexpr auto NOT_ZERO               = " != 0.";
	static constexpr auto CORRECT_BW             = "BW should be in range 0 - 64.";
	static constexpr auto BASE_UB                = "base > max.";
	static constexpr auto BASE_LB                = "base < min.";
	static constexpr auto OFFSET                 = "offset < 0.";
	static constexpr auto SMART_OFFSET           = "offset <= 0.";
	static constexpr auto IDX                    = "IDX <= 0.";
	static constexpr auto EMPTY_VECTOR           = "Empty Vector";
};
} // namespace fastlanes
#endif // FLS_COMMON_ASSERT_HPP
