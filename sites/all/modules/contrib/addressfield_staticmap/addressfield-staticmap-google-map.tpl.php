<?php $size = explode('x', $settings['size']); ?>

<div id="map_canvas" style="width: <?php print $size[0]; ?>px; height: <?php print $size[1]; ?>px;">
  <noscript><?php print $image; ?></noscript>
</div>

<script type="text/javascript">
  var address = '<?php print $address; ?>';
  
  var myOptions = {
    zoom: <?php print $settings['zoom']; ?>,
    mapTypeId: google.maps.MapTypeId.<?php print strtoupper($settings['maptype']); ?>
    //disableDefaultUI: true,
    //scrollwheel: false,
    //draggable: false,
    //disableDoubleClickZoom: true
  }
  var map = new google.maps.Map(document.getElementById('map_canvas'), myOptions);
  
  <?php foreach ($kml_paths as $kml_path): ?>
    var ctaLayer = new google.maps.KmlLayer('<?php print $kml_path; ?>');
    ctaLayer.setMap(map);
  <?php endforeach; ?> 
  
  var geocoder = new google.maps.Geocoder();

  geocoder.geocode({'address': address}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
      map.setCenter(results[0].geometry.location);
      var marker = new google.maps.Marker({
        map: map,
        position: results[0].geometry.location
        
      });
    }
 });
</script>