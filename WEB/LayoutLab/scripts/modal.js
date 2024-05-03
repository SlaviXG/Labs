document.addEventListener("DOMContentLoaded", function () {
  const modal = document.getElementById("ctc-modal");

  const btn = document.getElementById("ctc-btn");

  const span = document.getElementsByClassName("close")[0];

  function open() {
    document.getElementsByTagName("body")[0].style.overflow = "hidden";
    modal.style.opacity = 1;
    modal.style.visibility = "visible";
  }

  function close() {
    document.getElementsByTagName("body")[0].style.overflow = "auto";
    modal.style.opacity = 0;
    setTimeout(function () {
      modal.style.visibility = "hidden";
    }, 300);
  }

  btn.onclick = open;
  span.onclick = close;

  window.onclick = function (event) {
    if (event.target == modal) {
      close();
    }
  };
});
