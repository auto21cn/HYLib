// Room: d/kyoto/qianbending3
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "ǧ���");
set("long", @LONG
�������ǧ����ᴩ���������Ĵ�����Ҳ������Ľ���������
�йݵ����۴��αȡ�������Ĳ��Ҳ��ϴ�����Ѫ��������ά��������ʧ��
�������ۣ�Ҳ����̸��Ļĩʱ�ڸ��ɳ������͵Ĵ�˵������������ľ���
���˳�Ϊ���ε�ի����糴彣�ĵĴ��档

LONG );
set("exits",  ([
        "east"  : __DIR__"shangyuan2",
        "west"  : __DIR__"qianbending2",
        "north"  : __DIR__"kuiwu",
        "south"  : __DIR__"chashi",
      ]));
        setup();
        replace_program(ROOM);
}