package com.jnngl.dx4j.common;

public class Pointer {

  private final long address;

  public Pointer(long address) {
    this.address = address;
  }

  public long getAddress() {
    return address;
  }
}
