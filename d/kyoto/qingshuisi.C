// Room: d/kyoto/qingshuisi
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ˮ��");
set("long", @LONG
���Ǿ�������ϵ���Ժ�����ڹ�Ԫ�߾Ű��꣬�Ǵȶ���ʦ��������˵��
����ɮ�ĵ�һ�����ӣ���������±ߣ�ǰ�������յġ���̨����������һ
����ʮ�Ÿ��ߴ�Բľ֧�ţ��ߴ���ʮ�ס���Ժ�����������ṹ�ǳ����δ
ʹ��һ�����ӡ����������ľ���ɵ�ľ̨Ϊ�ձ������С�
LONG );
set("exits",  ([
        "east"  : __DIR__"gaoye",
      ]));
        setup();
        replace_program(ROOM);
}