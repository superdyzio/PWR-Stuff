# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('oceny', '0002_auto_20150603_0417'),
    ]

    operations = [
        migrations.AlterField(
            model_name='druzyna',
            name='Wynik_K',
            field=models.DecimalField(default=0.0, max_digits=4, decimal_places=2),
        ),
        migrations.AlterField(
            model_name='druzyna',
            name='Wynik_S',
            field=models.DecimalField(default=0.0, max_digits=4, decimal_places=2),
        ),
    ]
