// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrv32i__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vrv32i::Vrv32i(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrv32i__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , MemWrite{vlSymsp->TOP.MemWrite}
    , WriteData{vlSymsp->TOP.WriteData}
    , DataAdr{vlSymsp->TOP.DataAdr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vrv32i::Vrv32i(const char* _vcname__)
    : Vrv32i(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrv32i::~Vrv32i() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vrv32i___024root___eval_debug_assertions(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG
void Vrv32i___024root___eval_static(Vrv32i___024root* vlSelf);
void Vrv32i___024root___eval_initial(Vrv32i___024root* vlSelf);
void Vrv32i___024root___eval_settle(Vrv32i___024root* vlSelf);
void Vrv32i___024root___eval(Vrv32i___024root* vlSelf);

void Vrv32i::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrv32i::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrv32i___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vrv32i___024root___eval_static(&(vlSymsp->TOP));
        Vrv32i___024root___eval_initial(&(vlSymsp->TOP));
        Vrv32i___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vrv32i___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vrv32i::eventsPending() { return false; }

uint64_t Vrv32i::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vrv32i::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vrv32i___024root___eval_final(Vrv32i___024root* vlSelf);

VL_ATTR_COLD void Vrv32i::final() {
    Vrv32i___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrv32i::hierName() const { return vlSymsp->name(); }
const char* Vrv32i::modelName() const { return "Vrv32i"; }
unsigned Vrv32i::threads() const { return 1; }
void Vrv32i::prepareClone() const { contextp()->prepareClone(); }
void Vrv32i::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vrv32i::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vrv32i___024root__trace_decl_types(VerilatedVcd* tracep);

void Vrv32i___024root__trace_init_top(Vrv32i___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vrv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrv32i___024root*>(voidSelf);
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vrv32i___024root__trace_decl_types(tracep);
    Vrv32i___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vrv32i___024root__trace_register(Vrv32i___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vrv32i::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vrv32i::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vrv32i___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
