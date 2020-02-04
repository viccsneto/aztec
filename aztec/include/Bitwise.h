#pragma once

namespace Aztec {
  /**
  * Bitwise
  *
  * A class used to export the XOR, AND, OR, NOT Bitwise operators to Lua 5.1
  *
  * \author	Vicente Neto
  */
  class Bitwise {
  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * performs the operation a^b
    * @param a long left operand of the operation
    * @param b long right operand of the operation
    * @result The result of the operation a^b
    */
    static long XOR(long a, long b);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * performs the operation a&b
    * @param a long left operand of the operation
    * @param b long right operand of the operation
    * @result The result of the operation a&b
    */
    static long AND(long a, long b);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * performs the operation a|b
    * @param a long left operand of the operation
    * @param b long right operand of the operation
    * @result The result of the operation a|b
    */
    static long OR(long a, long b);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * performs the operation ~a
    * @param a long operand to the operation
    * @result The result of the operation ~a
    */
    static long NOT(long a);
  };
} // namespace Aztec