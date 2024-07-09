// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VaxiTop__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VaxiTop::VaxiTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VaxiTop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , wen{vlSymsp->TOP.wen}
    , ren{vlSymsp->TOP.ren}
    , read_data_m{vlSymsp->TOP.read_data_m}
    , addr_m{vlSymsp->TOP.addr_m}
    , write_data_m{vlSymsp->TOP.write_data_m}
    , read_data_s{vlSymsp->TOP.read_data_s}
    , addr_s{vlSymsp->TOP.addr_s}
    , write_data_s{vlSymsp->TOP.write_data_s}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VaxiTop::VaxiTop(const char* _vcname__)
    : VaxiTop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VaxiTop::~VaxiTop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VaxiTop___024root___eval_debug_assertions(VaxiTop___024root* vlSelf);
#endif  // VL_DEBUG
void VaxiTop___024root___eval_static(VaxiTop___024root* vlSelf);
void VaxiTop___024root___eval_initial(VaxiTop___024root* vlSelf);
void VaxiTop___024root___eval_settle(VaxiTop___024root* vlSelf);
void VaxiTop___024root___eval(VaxiTop___024root* vlSelf);

void VaxiTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VaxiTop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VaxiTop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VaxiTop___024root___eval_static(&(vlSymsp->TOP));
        VaxiTop___024root___eval_initial(&(vlSymsp->TOP));
        VaxiTop___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VaxiTop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VaxiTop::eventsPending() { return false; }

uint64_t VaxiTop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VaxiTop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VaxiTop___024root___eval_final(VaxiTop___024root* vlSelf);

VL_ATTR_COLD void VaxiTop::final() {
    VaxiTop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VaxiTop::hierName() const { return vlSymsp->name(); }
const char* VaxiTop::modelName() const { return "VaxiTop"; }
unsigned VaxiTop::threads() const { return 1; }
void VaxiTop::prepareClone() const { contextp()->prepareClone(); }
void VaxiTop::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VaxiTop::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VaxiTop___024root__trace_decl_types(VerilatedVcd* tracep);

void VaxiTop___024root__trace_init_top(VaxiTop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VaxiTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaxiTop___024root*>(voidSelf);
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VaxiTop___024root__trace_decl_types(tracep);
    VaxiTop___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VaxiTop___024root__trace_register(VaxiTop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VaxiTop::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VaxiTop::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VaxiTop___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
