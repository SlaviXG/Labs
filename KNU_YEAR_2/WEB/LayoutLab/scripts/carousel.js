document.addEventListener("DOMContentLoaded", function () {
  for (const carousel of document.getElementsByClassName("carousel")) {
    let intervalId;
    const container = carousel.getElementsByClassName("carousel-slides")[0];
    const slides = container.children;
    let activeIndex = 0;

    const nextBtn = carousel.getElementsByClassName("carousel-next")[0];
    const backBtn = carousel.getElementsByClassName("carousel-back")[0];

    function toggleActive(el) {
      el.classList.toggle("active");
    }

    function offset(pos) {
      const len = slides.length;
      const nextIndex = (len + ((activeIndex + pos) % len)) % len;
      toggleActive(slides[nextIndex]);
      toggleActive(slides[activeIndex]);
      activeIndex = nextIndex;
    }

    function resetInterval() {
      if (intervalId !== undefined) {
        clearInterval(intervalId);
      }
      intervalId = setInterval(() => {
        offset(1);
      }, 4 * 1000);
    }

    resetInterval();

    nextBtn.addEventListener("click", function () {
      offset(1);
      resetInterval();
    });

    backBtn.addEventListener("click", function () {
      offset(-1);
      resetInterval();
    });
  }
});
