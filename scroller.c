//Compile with:
//gcc -g radio_example_02.c -o radio_example_02 `pkg-config --cflags --libs elementary`

#include <Elementary.h>

static int val = 0;

static void _cb1(void *data, Evas_Object *obj, void *event_info);
static void _cb2(void *data, Evas_Object *obj, void *event_info);

EAPI_MAIN int
elm_main(int argc EINA_UNUSED, char **argv EINA_UNUSED)
{
   Evas_Object *win, *bx, *radio, *group, *ic, *scr;

   elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);

   win = elm_win_util_standard_add("radio", "Radio");
   elm_win_autodel_set(win, EINA_TRUE);

   scr = elm_scroller_add(win);
   evas_object_size_hint_weight_set(scr, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(scr, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_win_resize_object_add(win, scr);
   evas_object_show(scr);

   bx = elm_box_add(win);
   elm_box_horizontal_set(bx, EINA_TRUE);
   evas_object_size_hint_weight_set(bx, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_object_content_set(scr, bx);
   evas_object_show(bx);

   group = radio = elm_radio_add(win);
   elm_object_text_set(radio, "Radio 1");
   elm_radio_state_value_set(radio, 1);
   elm_radio_value_pointer_set(radio, &val);
   ic = elm_icon_add(win);
   elm_icon_standard_set(ic, "home");
   elm_object_part_content_set(radio, "icon", ic);
   elm_box_pack_end(bx, radio);
   evas_object_size_hint_weight_set(radio, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(radio, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(radio);
   evas_object_smart_callback_add(radio, "changed", _cb1, NULL);

   for (int i = 0; i < 50; ++i)
     {
        radio = elm_radio_add(win);
        elm_object_text_set(radio, "Radio 2");
        elm_radio_state_value_set(radio, 2);
        elm_radio_value_pointer_set(radio, &val);
        elm_radio_group_add(radio, group);
        ic = elm_icon_add(win);
        elm_icon_standard_set(ic, "file");
        elm_object_part_content_set(radio, "icon", ic);
        elm_box_pack_end(bx, radio);
        evas_object_size_hint_weight_set(radio, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
        evas_object_size_hint_align_set(radio, EVAS_HINT_FILL, EVAS_HINT_FILL);
        evas_object_show(radio);
        evas_object_smart_callback_add(radio, "changed", _cb2, NULL);
     }

   evas_object_show(win);

   elm_run();

   return 0;
}
ELM_MAIN()

static void
_cb1(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   printf("Radio 1 Clicked: val is now: %d\n", val);
}

static void
_cb2(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   printf("Radio 2 Clicked: val is now: %d\n", val);
}
