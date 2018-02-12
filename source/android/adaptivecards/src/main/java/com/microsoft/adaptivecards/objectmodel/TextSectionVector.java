/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.microsoft.adaptivecards.objectmodel;

public class TextSectionVector {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected TextSectionVector(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(TextSectionVector obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_TextSectionVector(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public TextSectionVector() {
    this(AdaptiveCardObjectModelJNI.new_TextSectionVector__SWIG_0(), true);
  }

  public TextSectionVector(long n) {
    this(AdaptiveCardObjectModelJNI.new_TextSectionVector__SWIG_1(n), true);
  }

  public long size() {
    return AdaptiveCardObjectModelJNI.TextSectionVector_size(swigCPtr, this);
  }

  public long capacity() {
    return AdaptiveCardObjectModelJNI.TextSectionVector_capacity(swigCPtr, this);
  }

  public void reserve(long n) {
    AdaptiveCardObjectModelJNI.TextSectionVector_reserve(swigCPtr, this, n);
  }

  public boolean isEmpty() {
    return AdaptiveCardObjectModelJNI.TextSectionVector_isEmpty(swigCPtr, this);
  }

  public void clear() {
    AdaptiveCardObjectModelJNI.TextSectionVector_clear(swigCPtr, this);
  }

  public void add(TextSection x) {
    AdaptiveCardObjectModelJNI.TextSectionVector_add(swigCPtr, this, TextSection.getCPtr(x), x);
  }

  public TextSection get(int i) {
    long cPtr = AdaptiveCardObjectModelJNI.TextSectionVector_get(swigCPtr, this, i);
    return (cPtr == 0) ? null : new TextSection(cPtr, true);
  }

  public void set(int i, TextSection val) {
    AdaptiveCardObjectModelJNI.TextSectionVector_set(swigCPtr, this, i, TextSection.getCPtr(val), val);
  }

}
