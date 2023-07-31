# **Da proof**

<!--
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">

</script>

<script type="text/x-mathjax-config">
MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>
-->

## **Tìm đạo hàm của hàm** $\text{floor}$

Xét đạo hàm của hàm $g(x) = \lfloor x \rfloor$. Theo định nghĩa, đạo hàm của hàm $g$ tồn tại khi:

$\displaystyle \lim_{\Delta \rightarrow 0^-}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0^+}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}}$

### **Nếu $x$ nguyên**

Xét giới hạn $\Delta \rightarrow 0^-$ của biểu thức, nhận thấy $\Delta$ tiến về $0^-$ nên $\Delta < 0$. Lại có $x \in \Z$, nên:

$\Rightarrow x + \Delta < x \\$
$\Rightarrow \lfloor x + \Delta \rfloor = x - 1 \\$
$\Rightarrow \displaystyle \lim_{\Delta \rightarrow 0^-}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0^-}{\frac{x - 1 - x}{\Delta}} = \lim_{\Delta \rightarrow 0^-}{\frac{-1}{\Delta}}$ <sup>[a]</sup>

Xét tương tự giới hạn $\Delta \rightarrow 0^+$ có $\Delta > 0$ nên:

$\Rightarrow x + \Delta > x \\$
$\Rightarrow \lfloor x + \Delta \rfloor = x \\$
$\Rightarrow \displaystyle \lim_{\Delta \rightarrow 0^+}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0^+}{\frac{x - x}{\Delta}} = \lim_{\Delta \rightarrow 0^+}{\frac{0}{\Delta}}$ <sup>[b]</sup>

Từ <sup>[a]</sup> và <sup>[b]</sup> có $\displaystyle \lim_{\Delta \rightarrow 0^+}$ khác với $\displaystyle \lim_{\Delta \rightarrow 0^-}$, nên đạo hàm của $g(x)$ không tồn tại với $x$ nguyên.

### **Nếu $x$ không nguyên**

Nhận xét rằng nếu $\Delta \rightarrow 0$ thì $x + \Delta$ luôn nằm trong khoảng $(\lfloor x \rfloor, \lceil x \rceil)$.

* Nếu $\Delta < 0$ thì $x + \Delta$ vẫn lớn hơn $\lfloor x \rfloor$, vì $\Delta \rightarrow 0$ nên luôn bé hơn phần thập phân của $x$.
* Tương tự, nếu $\Delta > 0$ thì $x + \Delta < \lceil x \rceil$, vì $\Delta$ nhỏ vô cùng và sẽ không bù đủ vào phần thập phân của $x$.

Nói cách khác, phần nguyên của $x$ không thay đổi khi cộng $\Delta$. Từ đó ta có:

$\displaystyle \lim_{\Delta \rightarrow 0^+}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0^+}{\frac{\lfloor x \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0^+}{\frac{0}{\Delta}} = 0 \\$

$\displaystyle \lim_{\Delta \rightarrow 0^-}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0^-}{\frac{\lfloor x \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0^-}{\frac{0}{\Delta}} = 0 \\$

$\displaystyle \lim_{\Delta \rightarrow 0}{\frac{\lfloor x + \Delta \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0}{\frac{\lfloor x \rfloor - \lfloor x \rfloor}{\Delta}} = \lim_{\Delta \rightarrow 0}{\frac{0}{\Delta}} = 0 \\$

$\displaystyle \Rightarrow \lim_{\Delta \rightarrow 0^+} = \lim_{\Delta \rightarrow 0^-} = \lim_{\Delta \rightarrow 0} = 0$

Do đó, đạo hàm của $g(x) = \lfloor x \rfloor$ không xác định tại $x$ nguyên và bằng $0$ tại mọi điểm $x$ khác.

## **Tìm giá trị nhỏ nhất của $f(x)$**

Có $f(x) = (N + x) \cdot \lfloor \log_{x}{V} + 1 \rfloor$ với $x$ là cơ số, $N$ là số phần tử và $V$ là giá trị lớn nhất, ta cầm tìm $x$ để tối thiểu hoá $f(x)$. Vì $x$ là cơ số nên $x > 1$ và $x \in \N$, ngoài ra $N$ và $V$ cũng $\in \N$.

Để tìm cơ số $x$ sao cho $f(x)$ tối thiểu, ta xét các điểm sao cho đạo hàm của $f(x) = 0$ hoặc không xác định.

### **Trường hợp $f'(x) = 0$**

Lấy đạo hàm của $f'(x)$ ta có:

$f'(x) = (N + x)' \cdot \lfloor \log_{x}{V} + 1 \rfloor + (N + x) \cdot \lfloor \log_{x}{V} + 1 \rfloor'$

Nhớ lại rằng đạo hàm của $\lfloor a \rfloor$ không xác định tại $a$ nguyên và bằng $0$ tại mọi điểm $a$ khác, nên ta xét trường hợp $\log_{x}{V} + 1 \notin \Z$.

$f'(x) = 0 \\$
$\Rightarrow (N + x)' \cdot \lfloor \log_{x}{V} + 1 \rfloor + (N + x) \cdot \lfloor \log_{x}{V} + 1 \rfloor' = 0 \\$
$\Rightarrow 1 \cdot \lfloor \log_{x}{V} + 1 \rfloor + (N + x) \cdot 0 = 0 \\$
$\Rightarrow \lfloor \log_{x}{V} + 1 \rfloor = 0 \Rightarrow \lfloor \log_{x}{V} \rfloor = -1 \\$
$\Rightarrow \log_{x}{V} \in (-1, 0) \\$
$\Rightarrow \log_{x}{V} < 0 \\$

Để $\log_{x}{V} < 0$ thì:

$\Rightarrow V = x^{-k}, k > 0 \\$
$\Rightarrow \frac{1}{x^k} = V \\$
$\Rightarrow \frac{1}{V} = x^k$

Vì $x > 1$ và $k > 0$ nên $x^k > 1$. Trong khi đó, $\frac{1}{V} \leq 1$ vì $V \in \N$, nên ta có thể rút ra rằng không tồn tại $x$ để $f'(x) = 0$.

### **Trường hợp $f'(x)$ không xác định**

Bây giờ ta sẽ xét các điểm mà $f'(x)$ không xác định, tức $\log_{x}{V} + 1 \in \Z$.

$\Rightarrow \log_{x}{V} \in \Z \\$
$\Rightarrow x^k = V, k \in \N \\$
$\Rightarrow x = \sqrt[k]{V}$

Do đó, để tìm cơ số $x$ ta chỉ cần lần lượt tìm từng căn bậc của $V$ rồi thử kết quả xem có đạt tối thiểu hay không. Một lưu ý nhỏ là cơ số cần phải là số nguyên, nên sau khi tính $x = \sqrt[k]{V}$ ta sẽ so sánh $\lfloor x \rfloor$ và $\lceil x \rceil$ và lấy $x$ có giá trị $f(x)$ nhỏ hơn. Nhớ rằng cơ số của chúng ta cũng phải lớn hơn 1, nên giá trị của $k$ sẽ không quá $\log_2{V}$:

$x = \lfloor \sqrt[k]{V} \rfloor > 1 \\$
$\Rightarrow \lfloor \sqrt[k]{V} \rfloor \geq 2 \\$
$\Rightarrow \sqrt[k]{V} \geq 2 \\$
$\Rightarrow 2^k \leq V \Rightarrow k \leq \log_2{V}$

Vì thế, quá trình này sẽ chỉ mất tối đa $\log_2{V}$ bước, không đáng kể so với độ phức tạp cần để thực hiện thuật toán sắp xếp.
