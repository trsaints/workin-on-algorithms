## Copyright (C) 2025 thiago
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{retval} =} plot_triangle (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: thiago <thiago@DESKTOP-4VP3KEP>
## Created: 2025-03-18

function r = plot_triangle(v1, v2, v3)
  x_vtx = [v1(1,1) v2(1,1) v3(1,1) v1(1,1)];
  y_vtx = [v1(1,2) v2(1,2) v3(1,2) v1(1,2)];

  figure;

  plot(x_vtx, y_vtx, 'k-', 'LineWidth', 2);
  hold on;

  fill(x_vtx(1:3), y_vtx(1:3), 'cyan');
  hold off;

  axis equal;
  xlabel('x');
  ylabel('y');

  r = [x_vtx, y_vtx];
endfunction
