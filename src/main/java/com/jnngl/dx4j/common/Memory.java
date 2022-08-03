package com.jnngl.dx4j.common;

import java.lang.reflect.Field;
import sun.misc.Unsafe;

public class Memory {

  private static final Unsafe unsafe;

  static {
    try {
      Field theUnsafe = Unsafe.class.getDeclaredField("theUnsafe");
      theUnsafe.setAccessible(true);
      unsafe = (Unsafe) theUnsafe.get(null);
    } catch (ReflectiveOperationException e) {
      throw new RuntimeException(e);
    }
  }

  public static Unsafe getUnsafe() {
    return unsafe;
  }

  public static short[] readShortArray(long address, int count) {
    if (count < 0) {
      return null;
    }

    short[] dst = new short[count];
    for (int i = 0; i < count; i++) {
      dst[i] = getUnsafe().getShort(address);
      address += 2;
    }
    return dst;
  }

}
