/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.microsoft.adaptivecards.objectmodel;

public class TextSection {
  private transient long swigCPtr;
  private transient boolean swigCMemOwn;

  protected TextSection(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(TextSection obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_TextSection(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public TextSection() {
    this(AdaptiveCardObjectModelJNI.new_TextSection__SWIG_0(), true);
  }

  public TextSection(String text, TextSectionFormat format) {
    this(AdaptiveCardObjectModelJNI.new_TextSection__SWIG_1(text, format.swigValue()), true);
  }

  public TextSection(String text, String originalText, TextSectionFormat format) {
    this(AdaptiveCardObjectModelJNI.new_TextSection__SWIG_2(text, originalText, format.swigValue()), true);
  }

  public String GetText() {
    return AdaptiveCardObjectModelJNI.TextSection_GetText(swigCPtr, this);
  }

  public String GetOriginalText() {
    return AdaptiveCardObjectModelJNI.TextSection_GetOriginalText(swigCPtr, this);
  }

  public TextSectionFormat GetFormat() {
    return TextSectionFormat.swigToEnum(AdaptiveCardObjectModelJNI.TextSection_GetFormat(swigCPtr, this));
  }

  public int GetDay() {
    return AdaptiveCardObjectModelJNI.TextSection_GetDay(swigCPtr, this);
  }

  public int GetMonth() {
    return AdaptiveCardObjectModelJNI.TextSection_GetMonth(swigCPtr, this);
  }

  public int GetYear() {
    return AdaptiveCardObjectModelJNI.TextSection_GetYear(swigCPtr, this);
  }

  public int GetSecond() {
    return AdaptiveCardObjectModelJNI.TextSection_GetSecond(swigCPtr, this);
  }

  public int GetMinute() {
    return AdaptiveCardObjectModelJNI.TextSection_GetMinute(swigCPtr, this);
  }

  public int GetHour() {
    return AdaptiveCardObjectModelJNI.TextSection_GetHour(swigCPtr, this);
  }

}
