// Room: d/kyoto/shangyuan2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ԭ");
set("long", @LONG
������Ǿ�����������ģ���ԭ��ǧ��Ľ��㴦��������������
Ⱥ���ϴ����߲������������ߵ��̵Ľ����������ڶ����������߾���ǧ��
��Ǿ����Ķ���������Ҳ������Ľ������йݵ����۴��αȡ�
LONG );
set("exits",  ([
        "south"  : __DIR__"shangyuan3",
        "north"  : __DIR__"shangyuan1",
        "west"  : __DIR__"qianbending3",
        "east"  : __DIR__"qianbending4",
      ]));
        setup();
        replace_program(ROOM);
}