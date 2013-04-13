#include <mruby.h>
#include "stdlib.h"
#include "mruby/numeric.h"

static mrb_value
fix_udiv(mrb_state *mrb, mrb_value x)
{
  mrb_value y;
  mrb_int a, b;

  mrb_get_args(mrb, "o", &y);
  a = mrb_fixnum(x);
  
  if (mrb_fixnum_p(y) && (b=mrb_fixnum(y)) != 0) {
    if (mrb_fixnum(y) == 0) {
      return mrb_float_value(str_to_mrb_float("nan"));
    }
    b = mrb_fixnum(y);
    return mrb_fixnum_value(a / b);
  }
  else {
    return mrb_fixnum_value(0);
  }
}

void
mrb_mruby_numeric_udiv_gem_init(mrb_state* mrb) {
  struct RClass *fixnum = mrb_class_get(mrb, "Fixnum");
  
  //mrb_define_method(mrb, fixnum,  "/",        fix_udiv,          ARGS_REQ(1));
  mrb_define_method(mrb, fixnum,  "udiv",     fix_udiv,          ARGS_REQ(1));
}

void
mrb_mruby_numeric_udiv_gem_final(mrb_state* mrb) {
  // finalizer
}
