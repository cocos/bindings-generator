#pragma once
\#include "base/ccConfig.h"
#if $macro_judgement
$macro_judgement
#end if 
\#include <type_traits>
\#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
\#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#if $hpp_headers
#for header in $hpp_headers
\#include "${header}"
#end for
#end if 
