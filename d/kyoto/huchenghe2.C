// Room: d/kyoto/huchenghe2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "���ǺӰ���");
set("long", @LONG
�����ǻ��Ǻӵİ��ߣ������貨��ˮ���գ�ɢ����ϲ�˵Ĺ⣬���Ǻӻ�
�Ƶľ��ǣ۾��������ݣ���������ʵ��й���������������˷ǣ����ǻʹ�
�ĺ���������Ȼʹ����Ȼ�𾴡�
LONG );
set("exits",  ([
        "south"  : __DIR__"hongqiao",
        "west"  : __DIR__"jinqiao",
      ]));
        setup();
        replace_program(ROOM);
}