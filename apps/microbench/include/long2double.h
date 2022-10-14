#pragma once


double long2double(uint64_t integer, uint8_t dot)
{
  bool is_neg = ((uint64_t)1<<63) & integer;
  uint64_t val_pos = is_neg? ~integer+1: integer;
  uint64_t float_mask = ~((uint64_t)-1 << dot);
  uint64_t part_float = val_pos & float_mask;
  uint64_t part_int = val_pos >> dot;

  double val = 0.0f;
  for (uint8_t i=0; i<dot; ++i) {
    val = (val + (part_float & 1)) * 0.5;
    part_float = part_float >> 1;
  }
  val += part_int;
  val = is_neg? val*-1: val;

  return val;
}
